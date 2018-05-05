var layer=function(x,y,nbN,nbI,nbO){
  console.log(windowHeight)
  this.x=x;
  this.y=y;
  this.nbNeurons = nbN;
  this.nbI=nbI;
  this.nbO=nbO;
  this.tabNeurones =[];

  this.show=function(et){
    for(var i=0;i<this.nbNeurons;i++){
      this.tabNeurones[i].show(et);
    }
}

};
