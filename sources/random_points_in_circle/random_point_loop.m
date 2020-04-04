function [px, py, t] = random_point_loop(radius, x,y) 
  px = 100;
  py = 100;
  t=0;
  while (px*px + py*py > 1)
     signx = 2*randi([0,1])-1;
     signy = 2*randi([0,1])-1;
     px = rand()*radius*signx;
     py = rand()*radius*signy;
     t=t+1;
  endwhile


endfunction
