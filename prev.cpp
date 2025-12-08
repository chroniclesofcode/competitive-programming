#include <bits/stdc++.h>
using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;

#define PQ_SZ 64

typedef struct {
    uint64_t ts; // timestamp
    timer_callback_t callback;
    void* callback_data;
    uint32_t id;
} timer_pqdata_t;

typedef struct {
    size_t size;
    timer_pqdata_t data[PQ_SZ];
} timer_pq_t;

static struct {
    volatile meson_timer_reg_t *regs;
    /* Add fields as you see necessary */
    timeout_id_t timeout_id;
    timeout_timebase_t timebase;
    timer_pq_t pq;
    uint32_t next_id;
} clock;

/* HEAP OPERATIONS */

static inline int timer_cmp(timer_pqdata_t *a, timer_pqdata_t *b)
{
    return (a->ts < b->ts);
}

static inline void timer_swap(timer_pqdata_t *a, timer_pqdata_t *b)
{
    timer_pqdata_t tmp = *a;
    *a = *b;
    *b = tmp;
}

static void heapify_up(size_t i)
{
    timer_pqdata_t *data = clock.pq.data;
    while (i > 0) {
        size_t par = (i-1)/2;
        if (!timer_cmp(&data[i], &data[par])) break;
        timer_swap(&data[i], &data[par]);
        i = par;
    }
}

static void heapify_down(size_t i)
{
    timer_pqdata_t *data = clock.pq.data;
    while (true) {
        size_t left = 2*i + 1;
        size_t right = left + 1;
        size_t curr = i;

        if (left < clock.pq.size && timer_cmp(&data[left], &data[curr])) curr = left;
        if (right < clock.pq.size && timer_cmp(&data[right], &data[curr])) curr = right;
        if (curr == i) break;

        timer_swap(&data[i], &data[curr]);
        i = curr;
    }
}

static int heap_push(timer_pqdata_t data) {
    if (clock.pq.size >= PQ_SZ) return -1;
    size_t idx = clock.pq.size;
    clock.pq.data[idx] = data;
    clock.pq.size++;
    heapify_up(idx);
    return 0;
}
static int heap_pop() {
    if (clock.pq.size == 0) return 1;
    clock.pq.size--;
    size_t curr_sz = clock.pq.size;
    if (curr_sz > 0) {
        clock.pq.data[0] = clock.pq.data[curr_sz];
        heapify_down(0);
    }
    return 0;
}

// note it's a pointer
static timer_pqdata_t* heap_top() {
    if (clock.pq.size == 0) {
        return NULL;
    }
    return &clock.pq.data[0];
}

static size_t timer_pq_find(uint32_t id) {
    for (size_t i = 0; i < clock.pq.size; i++) {
        if (clock.pq.data[i].id == id) {
            return i;
        }
    }
    return PQ_SZ;
}

static void heap_delete(size_t rem) {
    if (rem >= clock.pq.size)
        return;
    if (rem == 0) {
        heapify_down(0);
    } else {
        clock.pq.data[rem] = clock.pq.data[clock.pq.size-1];
        size_t par = (rem-1) / 2;
        if (timer_cmp(&clock.pq.data[rem], &clock.pq.data[par])) {
            heapify_up(rem);
        } else {
            heapify_down(rem);
        }
    }
    clock.pq.size--;
}

void solve() {
    heap_push(50, 1);
    int rm = heap_push(10, 2);
    heap_push(30, 3);

    
    while (tclock.pq.size > 0) {
        cout << "Len is : " << tclock.pq.size << endl;
        cout << "Top is: " << heap_top().ts << endl;
        heap_pop();
    }
    cout << "Len is : " << tclock.pq.size << endl;
    cout << "Top is: " << heap_top().ts << endl;
    heap_pop();
    cout << "Len is : " << tclock.pq.size << endl;
    cout << "Top is: " << heap_top().ts << endl;
    heap_pop();
    cout << "Len is : " << tclock.pq.size << endl;
}
/*

*/