# C++ 演算法與資料結構 Cheatsheet

> 本文件依據此 Repo 中的解題與面試題目（包含 LeetCode、Waymo、NVIDIA、Tesla、Milan 等經典題目）整理常用語法、STL 容器、核心資料結構與高頻演算法範本。

---

## 目錄 (Table of Contents)
1. [二分搜尋系列 (Binary Search, Lower Bound, Upper Bound)](#1-二分搜尋系列)
2. [優先佇列與堆積 (Priority Queue / Heap)](#2-優先佇列與堆積)
3. [排序與自訂比較器 (std::sort & Lambda)](#3-排序與自訂比較器)
4. [雙向鏈結串列與 LRU 快取 (std::list::splice)](#4-雙向鏈結串列與-lru-快取)
5. [二維網格 4 方向走訪技巧 (Grid Exploration)](#5-二維網格-4-方向走訪技巧)
6. [位元運算與狀態壓縮 (Bit Manipulation)](#6-位元運算與狀態壓縮)
7. [圖論：拓撲排序與環偵測 (Topological Sort / Cycle Detection)](#7-圖論拓撲排序與環偵測)
8. [圖論：Tarjan 割邊/橋演算法 (Critical Connections / Bridges)](#8-圖論tarjan-割邊橋演算法)
9. [快速選擇演算法 (QuickSelect 找第 K 小/大元素)](#9-快速選擇演算法-quickselect)
10. [動態規劃兩種核心風格 (Push DP vs. 記憶化搜尋)](#10-動態規劃兩種核心風格)
11. [系統與嵌入式控制：有限狀態機 (FSM Polling Controller)](#11-系統與嵌入式控制有限狀態機)
12. [自定義 Struct 作為 unordered_map 的 Key (Hash & operator==)](#12-自定義-struct-作為-unordered_map-的-key)
13. [完整範例：自定義 class Point3D 插入 unordered_map](#13-完整範例自定義-class-point3d-插入-unordered_map)
14. [Python Dijkstra 最短路徑範例](#14-python-dijkstra-最短路徑範例)

---

## 1. 二分搜尋系列

標頭檔：`<algorithm>`

### 核心特性比較
| 函式 | 回傳值 | 作用 |
| :--- | :--- | :--- |
| `std::binary_search` | `bool` | **只判斷是否存在**（`true` / `false`），不回傳下標或迭代器。 |
| `std::lower_bound` | `Iterator` | 查找**第一個大於或等於 ($\ge$)** `num` 的位置。 |
| `std::upper_bound` | `Iterator` | 查找**第一個大於 ($>$)** `num` 的位置。 |

> **注意**：陣列必須預先排序！取得下標透過：`it - nums.begin()`。

### (1) 嚴格遞增陣列（預設）
```cpp
vector<int> nums = {1, 3, 5, 5, 5, 7, 9};

// 1. binary_search: 只回傳是否存在
bool found = binary_search(nums.begin(), nums.end(), 5); // true

// 2. lower_bound: 第一個 >= 5 的位置 (index = 2)
auto lb = lower_bound(nums.begin(), nums.end(), 5);
int lb_idx = lb - nums.begin();

// 3. upper_bound: 第一個 > 5 的位置 (index = 5)
auto ub = upper_bound(nums.begin(), nums.end(), 5);
int ub_idx = ub - nums.begin();

// 判斷 target 是否真的存在於陣列中，並取得其下標：
if (lb != nums.end() && *lb == 5) {
    int target_idx = lb - nums.begin();
}
```

### (2) 從大到小的排序陣列（遞減排序）
必須傳入 `greater<int>()` 比較器：
```cpp
vector<int> desc = {9, 7, 5, 5, 5, 3, 1};

// 1. binary_search 需帶 greater<int>()
bool found = binary_search(desc.begin(), desc.end(), 5, greater<int>());

// 2. lower_bound: 第一個小於或等於 (<=) num 的位置
auto lb_desc = lower_bound(desc.begin(), desc.end(), 5, greater<int>());
int lb_idx = lb_desc - desc.begin();

// 3. upper_bound: 第一個小於 (<) num 的位置
auto ub_desc = upper_bound(desc.begin(), desc.end(), 5, greater<int>());
int ub_idx = ub_desc - desc.begin();
```

---

## 2. 優先佇列與堆積

標頭檔：`<queue>`

### 預設與自訂 Heap
```cpp
// 1. 預設是 Max-Heap（最大值在最頂部，內部使用 less）
priority_queue<int> max_heap;

// 2. Min-Heap（最小值在最頂部，使用 greater）
priority_queue<int, vector<int>, greater<int>> occupied_room;

// 3. 自訂 Lambda 比較器
// 注意：priority_queue 的比較邏輯與 sort 相反，return A > B 代表 A 的優先級比 B 低 (Min-Heap)
auto comp = [](const pair<int, int>& A, const pair<int, int>& B) {
    return A.second > B.second; // 依頻率升序 (小的在頂部)
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);

// Top K Frequent 經典維護範例：
for (auto it = freq.begin(); it != freq.end(); ++it) {
    q.push(make_pair(it->first, it->second));
    if (q.size() > k) {
        q.pop(); // 超過 k 個時剔除最小的，最後堆內留下最大的 k 個
    }
}
```

---

## 3. 排序與自訂比較器

標頭檔：`<algorithm>`

### 區間自訂排序 (Intervals Sort)
```cpp
vector<vector<int>> intervals = {{2, 6}, {1, 3}, {8, 10}};

// 依起點升序排序
sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
});
```

---

## 4. 雙向鏈結串列與 LRU 快取

標頭檔：`<list>`, `<unordered_map>`

### `std::list::splice` 在 $O(1)$ 移動節點
無須 `new` 或 `delete` 記憶體節點，直接將迭代器對應的節點指針移動到串列頭部：
```cpp
class LRUCache {
    int _capacity;
    list<pair<int, int>> record; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> LRU_map;

public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto got = LRU_map.find(key);
        if (got == LRU_map.end()) return -1;
        // 將命中節點搬移到 record 最前端 (O(1))
        record.splice(record.begin(), record, got->second);
        return got->second->second;
    }

    void put(int key, int value) {
        auto got = LRU_map.find(key);
        if (got != LRU_map.end()) {
            got->second->second = value;
            record.splice(record.begin(), record, got->second);
            return;
        }
        if (record.size() == _capacity) {
            int evict_key = record.back().first;
            LRU_map.erase(evict_key);
            record.pop_back();
        }
        record.push_front({key, value});
        LRU_map[key] = record.begin();
    }
};
```

---

## 5. 二維網格 4 方向走訪技巧

在矩陣搜尋（如島嶼問題、最長遞增路徑）中使用長度為 5 的陣列代替 4 個 if-else：
```cpp
const vector<int> dirs{-1, 0, 1, 0, -1}; // (dx, dy) 分別為 (-1,0), (0,1), (1,0), (0,-1)

for (int i = 0; i < 4; ++i) {
    int nx = x + dirs[i];
    int ny = y + dirs[i + 1];
    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
        // 合法的相鄰格子 (nx, ny)
    }
}
```

---

## 6. 位元運算與狀態壓縮

常用於連續序列判定、子集列舉與空間優化：
```cpp
int check = 0;
int val = 5;

check |= (1 << val);              // 將第 val 位置為 1
bool is_set = check & (1 << val); // 檢查第 val 位是否為 1
check &= ~(1 << val);             // 清除第 val 位

// 檢查是否包含連續 count 個連續數字（以 min_val 為起點）：
bool is_consecutive = (check >> min_val) == ((1 << count) - 1);
```

---

## 7. 圖論：拓撲排序與環偵測

### 三狀態染色法 (Three-color DFS)
* `0`：未訪問（Unvisited）
* `1`：訪問中（Visiting）——若遍歷過程中再次遇到 `1`，代表**發現有向環**！
* `2`：已訪問且安全（Visited）——該節點及其子路徑皆已確認無環，直接返回 `true` 剪枝。

```cpp
bool toposort(int u, const vector<vector<int>>& graph, vector<int>& state) {
    if (state[u] == 1) return false; // 遇環
    if (state[u] == 2) return true;  // 剪枝
    
    state[u] = 1;
    for (int v : graph[u]) {
        if (!toposort(v, graph, state)) return false;
    }
    state[u] = 2;
    return true;
}
```

---

## 8. 圖論：Tarjan 割邊/橋演算法

尋找無向圖中的 Critical Connections（割邊 / 橋）：
* `disc[u]`：節點 `u` 的 DFS 發現時間。
* `low[u]`：節點 `u` 或其子樹透過回邊（Back-edge）能追溯到的最小時間戳。
* **割邊判斷**：當子節點 `v` 無法回溯到 `u` 或更早的祖先，即 **`low[v] > disc[u]`** 時，邊 `(u, v)` 為割邊。

```cpp
void tarjanBridges(int u, const vector<vector<int>>& adj, vector<vector<int>>& bridges,
                   vector<int>& disc, vector<int>& low, vector<bool>& visited,
                   vector<int>& parent, int& time) {
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            tarjanBridges(v, adj, bridges, disc, low, visited, parent, time);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridges.push_back({u, v}); // (u, v) 是橋
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}
```

---

## 9. 快速選擇演算法 (QuickSelect)

在**平均 $O(N)$** 時間內找到未排序陣列中第 K 小（或第 K 大）的數：
```cpp
int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; ++j) {
        if (arr[j] <= pivot) swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

int quickSelect(vector<int>& arr, int l, int r, int k) {
    if (l <= r) {
        int idx = partition(arr, l, r);
        if (idx - l == k - 1) return arr[idx];
        if (idx - l > k - 1)  return quickSelect(arr, l, idx - 1, k);
        return quickSelect(arr, idx + 1, r, k - (idx - l + 1));
    }
    return -1;
}
```

---

## 10. 動態規劃兩種核心風格

### (1) 正向推式 DP (Push DP)
* **特點**：從當前已知狀態 $i$ 主動推展並更新未來的狀態 $dest$。
* **優勢**：在「每個點的下一個目標點明確」時，避免了向後回溯查詢的複雜度（通常能將 $O(N^2)$ 降至 $O(N)$）。
```cpp
// 例：Waymo 載客題目中
dp[dest] = max(dp[dest], dp[i] + payment);
```

### (2) 記憶化搜尋 (Top-down Memoization)
* **特點**：DFS + 快取矩陣 `dp`，初值設為 `-1`。
* **優勢**：只遍歷真正需要的子狀態，程式碼結構直觀，特別適合多維度網格搜尋。
```cpp
int dfs(vector<vector<int>>& grid, int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];
    dp[r][c] = 1;
    // 遍歷相鄰合法格子 ...
    dp[r][c] = max(dp[r][c], 1 + dfs(grid, nr, nc));
    return dp[r][c];
}
```

---

## 11. 系統與嵌入式控制：有限狀態機

在車載軟體、自動駕駛（如 Waymo 雨刷控制）與嵌入式韌體中，常以**非阻塞輪詢（Non-blocking Polling）**搭配有限狀態機（FSM）驅動硬體：

```cpp
class WiperController {
public:
    enum class State { IDLE, MOVING_LEFT, MOVING_RIGHT, CENTERING };

    void poll() {
        switch (state) {
            case State::IDLE:
                motor.MoveTo(Direction::kLeft);
                state = State::MOVING_LEFT;
                break;
            case State::MOVING_LEFT:
                if (left_sensor.WiperDetected()) {
                    leftPos = motor.GetPosition();
                    motor.MoveTo(Direction::kRight);
                    state = State::MOVING_RIGHT;
                }
                break;
            case State::MOVING_RIGHT:
                if (right_sensor.WiperDetected()) {
                    rightPos = motor.GetPosition();
                    midPos = (leftPos + rightPos) / 2.0f;
                    motor.MoveTo(Direction::kLeft);
                    state = State::CENTERING;
                }
                break;
            case State::CENTERING:
                // 實務考量：配合運動方向做判定，防範過衝 (Overshoot)
                if (motor.GetPosition() <= midPos) {
                    motor.Stop();
                    state = State::IDLE;
                }
                break;
        }
    }
private:
    State state = State::IDLE;
    float leftPos = 0.f, rightPos = 0.f, midPos = 0.f;
};
```
### 關鍵面試考點：
1. **過衝（Overshoot）**：避免使用微小區間（如 `mid ± 0.1`）判斷停止，高速時容易漏檢；應使用方向性單邊判斷（如由右往左時 `<= mid`）。
2. **看門狗/超時機制（Watchdog / Timeout）**：硬體可能卡死或感測器失效，各狀態需具備超時自保機制。
3. **感測器防抖（Debouncing）**：邊界觸發需濾除機械或電氣雜訊。

---

## 12. 自定義 Struct 作為 unordered_map 的 Key

標頭檔：`<unordered_map>`

在 C++ 中，`std::unordered_map<Key, Value>` 底層是雜湊表（Hash Table）。若要將自定義的 `struct`（如包含 `float x, y, z` 的 3D 座標點）作為 **Key**，必須滿足兩個不可或缺的條件：
1. **Hash 函數 (`std::hash`)**：計算該物件的 Hash Code (`size_t`) 來決定放入哪個 Bucket。
2. **相等比較運算子 (`operator==`)**：當發生 Hash 碰撞（Collision）時，雜湊表需用 `operator==` 來比對兩個物件是否真正相同。

---

### 定義 Struct
```cpp
struct Point {
    float x;
    float y;
    float z;

    // 條件一：必須重載 operator== 用以處理 Hash 碰撞
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};
```

---

### 寫法一：在 `std` 命名空間中特化 `std::hash`（最推薦、最乾淨）
宣告 `unordered_map` 時直接寫 `unordered_map<Point, int>` 即可，與內建型別無異。

```cpp
#include <unordered_map>

// 在 std namespace 中特化 hash<Point>
namespace std {
    template <>
    struct hash<Point> {
        size_t operator()(const Point& p) const {
            // 分別計算各欄位的 hash
            size_t h1 = hash<float>{}(p.x);
            size_t h2 = hash<float>{}(p.y);
            size_t h3 = hash<float>{}(p.z);

            // 使用經典的 Boost hash_combine 演算法混合 hash 值
            size_t seed = h1;
            seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= h3 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };
}

// 使用方式：直接像一般型別使用
unordered_map<Point, int> point_map;
point_map[{1.0f, 2.0f, 3.0f}] = 100;
```

---

### 寫法二：自定義 Hash Functor（作為模板的第 3 個參數）
如果不希望在 `std` 命名空間增加特化，可以定義自己的 Hash 結構體傳入模板：

```cpp
struct PointHash {
    size_t operator()(const Point& p) const {
        size_t h1 = std::hash<float>{}(p.x);
        size_t h2 = std::hash<float>{}(p.y);
        size_t h3 = std::hash<float>{}(p.z);

        // 簡化版混合（異或 + 位移）
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

// 使用方式：需傳入 PointHash 作為第三個模板參數
unordered_map<Point, int, PointHash> point_map;
point_map[{1.0f, 2.0f, 3.0f}] = 100;
```

---

### 面試進階追問與注意事項（Interview Follow-ups）

1. **浮點數 `float` 的精度問題（浮點數當 Key 的經典陷阱）**：
   * **問題**：浮點數計算常有微小誤差（例如 `0.1f + 0.2f != 0.3f`），若兩點物理上非常接近（例如差 $10^{-7}$），`operator==` 仍會判定為不同 Key。
   * **解決方案（空間網格離散化 / Voxel Grid Hashing）**：
     在自動駕駛（如 LiDAR 點雲、Waymo 空間切分）中，通常會先**離散化（Quantization）**成整數網格座標：
     ```cpp
     struct VoxelCoord {
         int ix, iy, iz;
         bool operator==(const VoxelCoord& o) const {
             return ix == o.ix && iy == o.iy && iz == o.iz;
         }
     };
     // 將浮點數座標轉換為網格：int ix = std::floor(x / voxel_size);
     ```
2. **`+0.0f` 與 `-0.0f` / `NaN`**：
   * IEEE 754 中 `+0.0f == -0.0f` 為 `true`，但某些自製 Hash 可能算出不同值導致邏輯不一致。
   * `NaN == NaN` 永遠為 `false`，嚴禁將包含 `NaN` 的點放入 Hash Table 中。
3. **對比 `std::map`**：
   * `std::map` 底層是紅黑樹（Red-Black Tree），**不需要 Hash 函數**，但需要提供 `<`（`operator<`）作為排序規則。

---

## 13. 完整範例：自定義 class Point3D 插入 unordered_map

> 情境：有一個自定義 **class**（成員是 `private`），要把 3D 點 `(x, y, z)` 當作 `unordered_map` 的 Key 來 insert / find。

### 實作步驟
1. class 內實作 `operator==`（`const` 成員函式）。
2. 寫一個 Hash Functor（`operator()` 必須是 `const`，回傳 `std::size_t`）。
   * 因為成員是 `private`，透過 **public getter** 取值（或宣告 `friend struct Point3DHash;`）。
3. 宣告：`unordered_map<Point3D, Value, Point3DHash>`。

```cpp
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

class Point3D {
public:
    Point3D(float x, float y, float z) : x_(x), y_(y), z_(z) {}

    float x() const { return x_; }
    float y() const { return y_; }
    float z() const { return z_; }

    // 條件 1：operator==（hash 碰撞時用來比對是否真的相同）
    bool operator==(const Point3D& other) const {
        return x_ == other.x_ && y_ == other.y_ && z_ == other.z_;
    }

private:
    float x_, y_, z_;
};

// 條件 2：hash function（簡單版）
struct Point3DHash {
    std::size_t operator()(const Point3D& p) const {
        std::size_t h1 = std::hash<float>{}(p.x());
        std::size_t h2 = std::hash<float>{}(p.y());
        std::size_t h3 = std::hash<float>{}(p.z());
        return h1 ^ (h2 << 1) ^ (h3 << 2);  // 位移避免 (1,2,3) 和 (3,2,1) 撞在一起
    }
};

int main() {
    std::unordered_map<Point3D, std::string, Point3DHash> cloud;

    // insert 的幾種方式
    cloud.insert({Point3D(1.f, 2.f, 3.f), "A"});
    cloud.emplace(Point3D(3.f, 2.f, 1.f), "B");
    cloud[Point3D(0.f, 0.f, 0.f)] = "Origin";  // operator[] 要求 Value 可預設建構

    // 查詢
    auto it = cloud.find(Point3D(1.f, 2.f, 3.f));
    if (it != cloud.end()) std::cout << "found: " << it->second << "\n";   // found: A
    std::cout << cloud.count(Point3D(3.f, 2.f, 1.f)) << "\n";              // 1

    // 走訪 (C++17 structured binding)
    for (const auto& [p, name] : cloud)
        std::cout << name << " (" << p.x() << ", " << p.y() << ", " << p.z() << ")\n";
}
```

### 關鍵規則（面試必講）
* **一致性**：若 `a == b`，則 `hash(a)` **必須** 等於 `hash(b)`（反之不必成立）。
* **Key 不可修改**：`unordered_map` 中的 Key 是 `const`，改了 Key 的值會讓它落在錯誤的 bucket。
* **為什麼要位移** `h1 ^ (h2 << 1) ^ (h3 << 2)`：XOR 有交換律，只寫 `h1 ^ h2 ^ h3` 的話 `(1,2,3)` 與 `(3,2,1)` 會碰撞。
* **浮點數誤差**：實務上（點雲、地圖）先量化成整數 voxel 座標再 hash，詳見第 12 節。
* **複雜度**：平均 $O(1)$；hash 品質差導致大量碰撞時退化為 $O(N)$。

---

## 14. Python Dijkstra 最短路徑範例

* **適用**：非負權重圖的單源最短路徑。
* **核心**：`heapq`（min-heap）每次取出目前距離最小的節點，做 **Relaxation**。
* **複雜度**：$O((V + E)\log V)$。

```python
import heapq
from collections import defaultdict


def dijkstra(n, edges, src):
    """回傳 src 到每個節點的最短距離與前驅節點 (用來還原路徑)。

    n: 節點數 (0 ~ n-1)
    edges: [(u, v, w), ...] 有向邊，權重 w >= 0
    """
    graph = defaultdict(list)
    for u, v, w in edges:
        graph[u].append((v, w))
        # 無向圖再加一行: graph[v].append((u, w))

    dist = [float("inf")] * n
    prev = [-1] * n
    dist[src] = 0
    pq = [(0, src)]  # (目前距離, 節點)，heapq 是 min-heap

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:  # Lazy deletion：過期的舊紀錄直接跳過
            continue
        for v, w in graph[u]:
            nd = d + w
            if nd < dist[v]:  # Relaxation
                dist[v] = nd
                prev[v] = u
                heapq.heappush(pq, (nd, v))
    return dist, prev


def build_path(prev, target):
    path = []
    while target != -1:
        path.append(target)
        target = prev[target]
    return path[::-1]


if __name__ == "__main__":
    edges = [(0, 1, 4), (0, 2, 1), (2, 1, 2), (1, 3, 1), (2, 3, 5), (3, 4, 3)]
    dist, prev = dijkstra(5, edges, 0)
    print("dist:", dist)                      # [0, 3, 1, 4, 7]
    print("path 0->4:", build_path(prev, 4))  # [0, 2, 1, 3, 4]
```

### 常見追問
* **為什麼不能有負權重？** Dijkstra 假設節點一旦被 pop 出來距離就確定；負邊會破壞這個假設 → 改用 **Bellman-Ford**（$O(VE)$）。
* **`if d > dist[u]: continue` 的用途？** Python `heapq` 不支援 decrease-key，所以同一節點可能被 push 多次，舊的紀錄直接跳過（Lazy deletion）。
* **只要到某個 target？** 在 `heappop` 出 `target` 時就可以直接 `return`（提早結束）。
* **網格 / 無權重圖？** 權重全為 1 時用 **BFS** 即可（$O(V + E)$）；權重只有 0/1 時用 **0-1 BFS**（`deque`）。
* **有啟發函數（如地圖導航）？** 改用 **A\***：priority = `g(n) + h(n)`。



