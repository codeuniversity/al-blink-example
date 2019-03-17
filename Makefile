deploy:
	scp Blink.ino pi@10.0.5.63:~/Arduino/Blink/
	ssh pi@10.0.5.63 "cd Arduino/Blink; amake -u uno Blink.ino /dev/ttyACM1"

deploy-transmitter:
	scp Transmitter.ino pi@10.0.5.63:~/Arduino/Transmitter/
	ssh pi@10.0.5.63 "cd Arduino/Transmitter; amake -u uno Transmitter.ino /dev/ttyACM0"

deploy-receiver:
	scp Receiver.ino pi@10.0.5.63:~/Arduino/Receiver/
	ssh pi@10.0.5.63 "cd Arduino/Receiver; amake -u uno Receiver.ino /dev/ttyACM1"
