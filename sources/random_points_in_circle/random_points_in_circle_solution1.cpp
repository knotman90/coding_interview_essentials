auto generate_random_point_in_circle()
{
  static std::uniform_real_distribution<double> dist_radius(0, 1);
  static std::uniform_real_distribution<double> dist_angle(0, 2 * M_PI);
  const auto r     = radius * sqrt(dist_radius(rnd));
  const auto theta = dist_angle(rnd);
  const auto x     = r * cos(theta);
  const auto y     = r * sin(theta);
  return std::make_pair{ x + x_center, y + y_center };
}