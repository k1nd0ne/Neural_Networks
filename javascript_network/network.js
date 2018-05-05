var network=function(x,y,arch){
  var sep =0;
  this.x=x;
  this.y=y;
  var val_max;
  this.archi = arch;
  this.tabCoordinates=[];
  var ecart = width/(this.archi.length+1);
  val_max = Math.max(...this.archi);
  var rad =windowHeight/(val_max+5);
  this.nbLayers = this.archi.length;
  this.tabLayers =[];
  for(var i=0;i<this.nbLayers;i++){
    var nbI,nbO;
    if(i==0){
      nbI = 1;
      nbO=this.archi[i+1];
    }else if (i==this.nbLayers-1){
      nbI = this.archi[i-1];
      nbO = 1;
    }else{
      nbI = this.archi[i-1];
      nbO = this.archi[i+1];
    }
    var l = new layer(this.x+(i*ecart),(val_max-this.archi[i])*(rad/2),this.archi[i],nbI,nbO);
    for(var j=0;j<this.archi[i];j++){
      l.tabNeurones.push(new neuron(l.x,l.y+((rad+sep)*j)+50,rad,nbI,nbO,200));
      var coord = [l.x,l.y+((rad+sep)*j)+50];
      this.tabCoordinates.push(coord);
    }
    this.tabLayers.push(l);
  }

  this.show=function(info,info2,info3){
    strokeWeight(1);
    stroke(255);
    var z=0;
    var i=0;
    var cpt=0;
    var total=0;
    for(var x=0;x<this.archi.length;x++){
      total+=this.archi[x];
    }
    var somme = this.archi[z];
    while(i<total){
      stroke(255);
      for(var j=0;j<this.archi[z+1];j++){
        if(i<this.archi[0]){
          textSize(20);
          text(info2[i],this.tabCoordinates[i][0]-70,this.tabCoordinates[i][1]);
          line(this.tabCoordinates[i][0],this.tabCoordinates[i][1],this.tabCoordinates[i][0]-50,this.tabCoordinates[i][1])
        }
        line(this.tabCoordinates[i][0],this.tabCoordinates[i][1],this.tabCoordinates[j+somme][0],this.tabCoordinates[j+somme][1]);

      }
      i++;
      cpt++;
      if(cpt==this.archi[z]){
        cpt=0;
        z++;
        somme+=this.archi[z];
      }
    }
    for(var j=total-this.archi[(this.archi.length)-1];j<total;j++){
      textSize(20);
      text(info3[j-(total-this.archi[(this.archi.length)-1])],this.tabCoordinates[j][0]+50,this.tabCoordinates[j][1]);
      line(this.tabCoordinates[j][0],this.tabCoordinates[j][1],this.tabCoordinates[j][0]+50,this.tabCoordinates[j][1]);
    }
    var print =[];
    var offset;
    var cpt;
    var x;
    var k=0;
    for(var i=0;i<this.nbLayers;i++){
      for(var j=0;j<this.tabLayers[i].nbNeurons;j++){
        if(i>0){
          offset= this.tabLayers[i-1].tabNeurones[0].nbrOutput;
        }else{
          offset=0;
        }
        cpt = this.tabLayers[i].tabNeurones[0].nbrInput;
        x=0;
        while(x<cpt){
          print.push(info[k+(offset*x)]+"\n");
          x++;
        }

        this.tabLayers[i].tabNeurones[j].show(print,cpt);
        print = [];
        k++;
      }
    }
  }

};
