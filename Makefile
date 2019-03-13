deploy:
	scp Blink.ino pi@10.0.5.63:~/Arduino/Blink/
	ssh pi@10.0.5.63 "cd Arduino/Blink; amake -u uno Blink.ino /dev/ttyACM0" |& grep '#'

noisy-deploy:
	scp Blink.ino pi@10.0.5.63:~/Arduino/Blink/
	ssh pi@10.0.5.63 "cd Arduino/Blink; amake -u uno Blink.ino /dev/ttyACM0"
