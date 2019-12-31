# TraffcFlowController
Automated traffic control system that uses realtime object recognition and tracking to capture the flow of vehicles at an intersection. It also handles the operation of the corresponding traffic signals based on this information.

Execute the `monitor.py` python file using `python monitor.py` command.

You can have your CCTV feed files in the `/CCTV_feed directory` and link them via setting path in code. 
If you want your input video stream from an attached webcam use `cv2.VideoCapture(0)` to initialize the video stream object.

The program outputs signal denoting the traffic density to the `arduino_ip.txt` file which is read by the arduino controller to execute the traffic signalling program based on the traffic density.
