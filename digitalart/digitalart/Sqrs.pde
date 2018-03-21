class Sqrs {
  
  PVector loc;
  float radius;
  color c;
  
  Sqrs(PVector _loc, float _radius){
    loc = _loc;
    radius = _radius;
    c = lerpColor(c1, c2, sq(loc.mag() / 320));
    //c2 = lerpColor(c1, c2, sq(loc.mag() / 50));
  }
  
  void display(){
    fill(c);
    strokeWeight(1);
    stroke(c1);
    float r = time > duration ? radius: easeOutElastic(time, 0, radius, duration);
    rect(loc.y, loc.x, r * 3, r * 3);
  }
  
  float easeOutElastic(float t, float b, float c, float d){
    float s = 1.70158;
    float a = c;
    if(t == 0)
      return b;
    t /= d;
    if(t == 1)
      return b + c;
    float p = d * 0.3;
    if(a < abs(c)){
      a = c;
      s = p / 4;
    } else {
      s = p / (2 * PI) * asin(c / a);
    }
    return a * pow(2, -10 * t) * sin((t * d - s) * (2 * PI) / p) + c + b;
  }
}