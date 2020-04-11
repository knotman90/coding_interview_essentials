function [px, py] = buggy_random_point(radius, x,y)
  r = rand()*radius;
  theta = rand()*2*pi;
  px = r * sin(theta);
  py = r *cos(theta);
endfunction
