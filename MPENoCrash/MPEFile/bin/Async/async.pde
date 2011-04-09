import processing.serial.*;
import mpe.config.*;
import mpe.client.*;

Serial myPort;
AsyncClient client;
String c = "c";
String p = "p";
String d = "d";
String b = "b";
String z = "z";
boolean started = false;
long startedTime = 0;
boolean start = false;
long startTime = 0;

void setup() {

  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0],9600); 
  myPort.clear();
  myPort.bufferUntil('\n');

  client = new AsyncClient("localhost",9003);

}

void draw() {
}

void keyPressed() {
  if (key        == 'c') {
    client.broadcast(c);
  } 
  else if (key   == 'b') {
    client.broadcast(b);
  }
  else if (key   == 'd') {
    client.broadcast(d);
  }
   else if (key  == 'z') {
    client.broadcast(z);
  }
}

void serialEvent(Serial myPort) {
  String myString    = myPort.readStringUntil('\n');
  if (myString      != null) {
    myString         = trim( myString );
    String sensors[] = split( myString, ',' );

    for (int sensorNum = 0; sensorNum < sensors.length; sensorNum+=1) {
      print( sensors[sensorNum] + ": " + sensors[sensorNum] + ", " );
    }
    println();
    int tilt     = int(sensors[0]);
    int button   = int(sensors[1]);
    int domino   = int (sensors[3]);
    int piezo    = int(sensors[4]);
    //int myNumber = int(myString);//commented out
    //println(myNumber);


    ///////////Code for Laver////////////
    if(tilt == 1 && !started) {

      client.broadcast(b);
      started = true;
      startedTime = millis();
    }

    if (millis() - startedTime > 800 && started) {

      client.broadcast(b);
      started = false;
    }
    ///////////Code for Piezo////////////
    if(piezo == 1 && !started) {

      client.broadcast(z);
      started = true;
      startedTime = millis();
    }

    if (millis() - startedTime > 800 && started) {

      client.broadcast(z);
      started = false;
    }

    ///////////Code for Button////////////
    if(button == 1 && !start) {

      client.broadcast(d);
      start = true;
      startTime = millis();
    }

    if (millis() - startTime > 2000 && start) {

      client.broadcast(c);
      start = false;
    }
  }
}


