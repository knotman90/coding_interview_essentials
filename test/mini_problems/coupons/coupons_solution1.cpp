#include <numeric>
#include <priority_queue>

int coupons_priority_queue(std::vector<int> &P)
{
  double original_cart_total_price = std::accumulate(P.begin(), P.end(), 0.0);
  const double half_original_cart_total_price = original_cart_total_price / 2.0;

  std::priority_queue<double, std::vector<double>> prices_after_coupons(
      P.begin(), P.end());
  int ans = 0;
  while (original_cart_total_price > half_pollution)
  {
    const auto best = prices_after_coupons.top();
    prices_after_coupons.pop();
    const double money_saved = best / 2.0;

    original_cart_total_price -= money_saved;
    prices_after_coupons.push(money_saved);
    ans++;
  }
  return ans;
}
