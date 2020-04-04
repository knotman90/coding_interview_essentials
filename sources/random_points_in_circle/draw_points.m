function draw_points(n)
   clf(1);
  % n is the total number of points
  px = zeros(1,n);
  py = zeros(1,n);
  
  tries = 0;
  for i =0:n
    %[x,y] = buggy_random_point(1,0,0);
   % [x,y,t] = random_point_loop(1,0,0);
   [x,y] = random_sqrt_area(1,0,0);
   % tries = tries + t;
    px(i+1) = x;
    py(i+1) = y;
  endfor
  
  average = tries/n
 
  
  % Plot a circle.
  angles = linspace(0, 2*pi, n); 
  radius = 1;
  xCenter = 0;
  yCenter = 0;
  cx = radius * cos(angles) + xCenter; 
  cy = radius * sin(angles) + yCenter;
  % Plot circle.
  plot(cx, cy, 'b-', 'LineWidth', 2);
  % Plot center.
  hold on;
  plot(xCenter, yCenter, 'k+', 'LineWidth', 2, 'MarkerSize', 16);
  grid on;
  axis equal;
  xlabel('X', 'FontSize', 16);
  ylabel('Y', 'FontSize', 16);
  
  
  
  % Plot random points.
  plot(px, py, 'r.', 'MarkerSize', 1);
  
 
  rectangle('Position',[-1 -1 2 2], 'LineWidth',3,  'EdgeColor' , [0 .5 .5])
  
endfunction
