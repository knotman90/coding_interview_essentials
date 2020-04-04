function [px, py] = random_sqrt_area(radius, x,y)
  area = pi*radius*radius*rand(); %random area
  r = sqrt(area/pi);
  theta = rand()*2*pi;
  px = r * sin(theta);
  py = r *cos(theta);
endfunction
