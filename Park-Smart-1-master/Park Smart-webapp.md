# Park Smart

## Webapp

### Overview

The webapp is desgined in Angular 9 and serves to expose an interface that allows visitors to reserve parkings for their vehicles in a dedicated parking lot. A booking must be confirmed at the time of parking by a unique access code generated at the time of booking. Another interface is exposed to the user at the parking area and in charge of this activity. Once a parkng lot is booked, the user is allowed to as much leeway to leave his car in the parking assigned to him as a specifically set timeout (which in our case for demo purposes is 10s).

### Technical Insights

The component driven architecture in Angular makes way for a dynamic system in which the number of operable parkings can be directly set in the backend without having to make subsequent changes. **Angular Routing** took care of the interface that accepts the unique user access code at the parking lot. The open source node module **AngularFire** is responsible for communication of the webapp with **Firebase** real-time database that holds values representing the state of the parking in among - vacant, booked and occupied. 2-way binding in Angular has been exploited in building the UI that mirrors the status values in the back-end by binding certain values of the JSON snapshot from the database with the user-friendly fields on the front-end. This makes way for changes in the back-end to immediately update values in the webapp interface making it dynamic and fast. What makes an Angular app aesthetic is the **Angular Material** add-on integration which in our case has furnished snackbars, modal dialogs and material cards.

### Tools

- [Angular 9](https://angular.io/)
- [Angular Material](https://material.angular.io/)
- [AngularFire](https://github.com/angular/angularfire)