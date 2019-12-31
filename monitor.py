import cv2
from sys import argv
sr,_file = argv
_dir='/home/sid/Documents/Hackathon_627'
fname='arduino_ip.txt'
car_cascade = cv2.CascadeClassifier(_dir+'/Classifier/cars.xml')

if _file == 'high':
    cam=cv2.VideoCapture(_dir+'/CCTV_feed/low_t.mp4')
elif _file == 'new':
    cam=cv2.VideoCapture(_dir+'/CCTV_feed/new.mp4')

#img = cv2.imread('sc.png', 1)
ncars=0
frames=0
param=0
avg=[]
i=0
fo = open(fname,'w')
fo.truncate()
fo.close()
while True:
    ret,img=cam.read() 
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    cars = car_cascade.detectMultiScale(gray, 1.1, 1)
    fo = open(fname,'a')
    fo.truncate()
    for (x, y, w, h) in cars:
        cv2.rectangle(img, (x,y), (x+w,y+h), (0,0,255), 1)
        ncars = ncars + 1
    
    frames+=1

    if frames==15:
        frames=0
        avg.append(ncars)
        i+=1

    if i==10:
        i=0
        for x in range(10):
            param+=avg[x]

        if param < 170:
            #print param
            fo.write('0')
            fo.write('\n')
            print 'Low Traffic: Signal 0 sent to Traffic Light Controller'
        else:
            fo.write('1')
            fo.write('\n')
            print 'Heavy Traffic: Signal 1 sent to Traffic Light Controller'
        print '\n'
        #print param
        avg=[]
        param=0    
    fo.close()
    ncars=0

    cv2.imshow('im',img)
    cv2.waitKey(20)

