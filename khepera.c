if czujniki us > np.30/50 odo_goto(x, y (czyli np.30,0))
int max_us=0;
int maxi;
//POZA PĘTLĄ
for(i=0;i<5;i++)
{
  usvalues[i]=Buffer(i);

  if (usvalues[i]>max_us)
  {
    max_us=usvalues[i];
    maxi=i;
  }

}
if (maxi==0){
  kh4_set_position(poz_l-10000,poz_r+10000,dsPic);
  sleep(2);
}
else if(maxi==1){
  kh4_set_position(poz_l-5000,poz_r+5000,dsPic);
  sleep(2);
}
else if(maxi==2){
  kh4kh4_set_position(5000,5000,dsPic);
  sleep(2);
}
else if(maxi==3){
  kh4_set_position(poz_l+5000,poz_r-5000,dsPic);
  sleep(2);
}
else if(maxi==4){
  kh4_set_position(poz_l+10000,poz_r-10000,dsPic);
  sleep(2);
}

float gotox,gotoy;
if (usvalues[2]>30 && usvalues[2]<1000)
{
  gotox=result_x+0.1;
  gotoy=result_y;
  odometry_goto(gotox,gotoy);
}
else if(usvalues[0]>30 && usvalues[0]<1000)
{
  //kh4_set_position(poz_l-10000,poz_r+10000,dsPic);
  odometry_goto(result_x,result_y-0.1);
}
else if(usvalues[4]&& usvalues[4]<1000)
{
  //kh4_set_position(poz_l+10000,poz_r-10000,dsPic);
  odometry_goto(result_x,result_y+0.1);
}
//dopóki nie dojedzie do punktu
while(atgoal==0)
{
  odometria();
  odometry_goto();
  kh4_set_speed(r_speed_left,r_speed_right,dsPic);
}
