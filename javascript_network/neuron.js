var neuron=function(x,y,r,nbI,nbO,Bl){

  this.x=x;
  this.y=y;
  this.radius=r;
  this.nbrInput=nbI;
  this.nbrOutput=nbO;
  this.BranchLength=Bl;

  this.show=function(info,cpt){
    fill(200,0,0);
    noStroke();
    ellipse(this.x,this.y,r,r);
    fill(255);
    strokeWeight(2);
    textSize(10);
    if(mouseX> this.x-r/2 && mouseX< this.x+r/2 && mouseY> this.y-r/2 && mouseY< this.y+r/2){
      stroke(0,0,150);
      fill(20);
      rect(mouseX+50,mouseY,60,(cpt+1)*20);
      fill(255);
      noStroke();
      text(info,mouseX+60,mouseY+20);
    }

  }

};
