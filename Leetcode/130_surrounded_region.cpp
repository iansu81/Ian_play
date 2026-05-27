class Solution {
    public:
        void solve(vector<vector<char>>& board) {

            // Step1: 只有連到最外層的O不會被清掉，所以先找最外層的O
            int n_rows = board.size();
            int n_cols = board[0].size();
            stack<std::pair<int, int>> s;
            for(int i = 0; i < n_rows; i++) {
                if(board[i][0] == 'O') s.push({i, 0});
                if(board[i][n_cols-1] == 'O') s.push({i, n_cols-1});;
            }
            for(int i = 1; i < (n_cols-1); i++) {
                if(board[0][i] == 'O') s.push({0, i});
                if(board[n_rows-1][i] == 'O') s.push({n_rows-1,i});
            }

            // Step2: 針對最外層的O做DFS，同時間把這些變成"S"
            std::vector<int> direction = {1,0,-1,0,1};
            std::pair<int, int> loc;
            while(!s.empty()) {
                
                loc = s.top();
                s.pop();
                board[loc.first][loc.second] = 'S';
                for(int i = 0; i < 4; i++) {
                    int new_r = loc.first+direction[i];
                    int new_c = loc.second+direction[i+1];
                    if( new_r >= 0 && new_r < n_rows && new_c >= 0 && new_c < n_cols && board[new_r][new_c] == 'O') s.push({new_r, new_c});
                }
    
            }

            // Step 3: 有變成"S"的代表有連到最外層, 還是維持"O"的代表沒有連到外面, 所以要清掉
            for(int i = 0; i < n_rows; i++){
                for(int j = 0; j < n_cols; j++) {
    
                    if( board[i][j] == 'S') board[i][j] = 'O';
                    else if( board[i][j] == 'O') board[i][j] = 'X';
    
                }
    
            }
    
            }
            
    };