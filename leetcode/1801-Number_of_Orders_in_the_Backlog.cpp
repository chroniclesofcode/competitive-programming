class Solution {
public:
    using Price = int;
    int ans = 0;
    std::map<Price, Price, std::greater<Price>> m_bids;
    std::map<Price, Price, std::less<Price>> m_asks;

    void MatchOrders() {
        while (m_bids.size() && m_asks.size()) {
            auto &[bid_p, bid_q] = *m_bids.begin();
            auto &[ask_p, ask_q] = *m_asks.begin();
            if (bid_p < ask_p)
                return;
            Price to_fill = std::min(bid_q, ask_q);
            bid_q -= to_fill;
            ask_q -= to_fill;
            ans -= to_fill * 2;
            if (bid_q == 0) {
                m_bids.erase(bid_p);
            }
            if (ask_q == 0) {
                m_asks.erase(ask_p);
            }
        }
    }

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int md = (int)1e9 + 7;
        for (auto &o : orders) {
            int price = o[0], amount = o[1], side = o[2];
            if (side == 0) {
                m_bids[price] += amount;
            } else {
                m_asks[price] += amount;
            }
            ans += amount;
            MatchOrders();
            ans %= md;
        }
        return (ans + md) % md;
    }
};
