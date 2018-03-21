/**
* easing test
*
* @author aa_debdeb
* @date 2016/11/20
*/

float time = 0;
float duration = 200; 
ArrayList<Circle> circles;
color c1, c2;
bgFade bgc= new bgFade(); // Created a new background class that changes the background color

void setup(){
  size(1600, 900);  // Changed screen resolution
  //fullScreen();
  mousePressed();  
}

void draw(){
  translate(width / 2, height / 2);
  bgc.display();  // New background class being applied
  //keyPressed();
  for(Circle c: circles){
    c.display();
  }
  time += 1;
}

void keyPressed(){  // Pressing 's' creates smaller circles while pressing 'b' makes bigger ones
  if (key=='l') {
    float radius= random(1,10);
    for (int j=0; j<circles.size(); j++){
      Circle currentCircle= circles.get(j);
      currentCircle.radius= radius;
    }
  }
  time = 1;
  if (key=='b') {
  float radius= random(11,50);
    for (int j=0; j<circles.size(); j++){
      Circle currentCircle= circles.get(j);
      currentCircle.radius= radius;
    }
  time = 1; // Resets the time for the easeOutElastic() part of the Circle class
  }
}

void mousePressed(){
  c1 = color(random(255), random(255), random(255));
  c2 = color(random(255), random(255), random(255));
  circles = new ArrayList<Circle>();
  for(int i = 0; i < 10000; i++){
    float radius = random(5, 40);
    float locSize = map(sqrt(random(1)), 0, 1, 0, width/4); // Changes where the circles are created in relation to the window size. 
    float locAng = random(TWO_PI);
    PVector loc = new PVector(locSize * cos(locAng), locSize * sin(locAng));    
    boolean isOverlapped = false;
    for(Circle other: circles){
      if(PVector.dist(loc, other.loc) < (radius + other.radius) * 2){
        isOverlapped = true;
        continue;
      }
    }
    if(!isOverlapped){
      circles.add(new Circle(loc, radius));
    }
  }  
  time = 1;
}