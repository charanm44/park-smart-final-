# Park-Smart With LoRa

Technology Stack:  C++ | JavaScript | AWS | Cloud | HTML5 | CSS3.

#### Summary
This project presents the development of a cost effective, easy to use smart parking product based on embedded IoT and providing end to end solution using the cutting edge LoRa technology. 
* It is an IoT based project using Hi-letgo ESP32 LoRa chips to LoRa RX, which uploads data to cloud in real-time
* Effort to create a unique smart-parking system.
* Also employed a web page and mobile app for monitoring the parking spots

please go to http://18.144.88.150/ for the web-page

1.	Hardware instructions
Upload IR_LCD_LoRaTX.ino into the transmitter NodeMCU with IR sensors and LCD
Upload LoRa_Receiver.ino to the receiver NodeMCU.
The transmitter send the packets of data to the receiver.
The receiver segregates the data as per the code.
The Receiver is connected to WiFi. Change the SSD and password as required.
The receiver uploads the data into Firebase in real time.
2.	Web Application instructions
To start up our frontend and backend, all you need to do is SSH into the AWS EC2 instance and run ‘sudo service apache2 start’ This will run the Angular JS web application
ssh -i "Park-Smart.pem" ubuntu@ec2-18-144-88-150.us-west-1.compute.amazonaws.com


# Park Smart

## Webapp

### Overview

The webapp is desgined in Angular 9 and serves to expose an interface that allows visitors to reserve parkings for their vehicles in a dedicated parking lot.
A booking must be confirmed at the time of parking by a unique access code generated at the time of booking.
Another interface is exposed to the user at the parking area and in charge of this activity. 
Once a parkng lot is booked, the user is allowed to as much leeway to leave his car in the parking assigned to him as a specifically set timeout (which in our case for demo purposes is 10s).

### Technical Insights

The component driven architecture in Angular makes way for a dynamic system in which the number of operable parkings can be directly set in the backend without having to make subsequent changes.
 **Angular Routing** took care of the interface that accepts the unique user access code at the parking lot.
 The open source node module **AngularFire** is responsible for communication of the webapp with
 **Firebase** real-time database that holds values representing the state of the parking in among - vacant, booked and occupied.
 2-way binding in Angular has been exploited in building the UI that mirrors the status values in the back-end by binding certain values of the JSON snapshot from the database with the user-friendly fields on the front-end.
 This makes way for changes in the back-end to immediately update values in the webapp interface making it dynamic and fast. What makes an Angular app aesthetic is the **Angular Material** add-on integration which in our case has furnished snackbars, modal dialogs and material cards.

### Tools

- [Angular 9](https://angular.io/)
- [Angular Material](https://material.angular.io/)
- [AngularFire](https://github.com/angular/angularfire)
