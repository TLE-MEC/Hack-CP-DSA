

// Points to note in the problem:
// 1. a binary matrix of m*n is given, 1--> obstacle  , 0--> empty
// 2. Aim is to move from (0,0) cell to (m-1,n-1) in minimum no of moves using empty cells.
// 3. Moves allowed: Up,down, right, left
// 4. You can remove at most k 1's (ie obstacles) to achieve goal in minimum steps.


// Explanation of the idea:
// The main thing which makes this problem difficult is the constraint k (our choice of removing k no of obstacles from our path).
// Without this, the problem can easily be solved with a BFS starting from the source (top-left cell) to destination (bottom-right cell)
// keeping the count for steps.

// In the normal BFS in a grid (approach mentioned in the above line), each cell's state depends on only one parameter (its distance from the source).
// So, if we visit one cell once we donot need to visit it again as it already has its minimum distance obtained from its previous visit.
// But with the constraint that we can remove k obstacles, each cell will have state depending on two parameters: 1. its distance from the source and
// 2. the number of obstacles which we can remove. So, if we have already visited a cell (x,y) with state (x,y,d1,ob1) and later if we again find the same cell
// (x,y) with state (x,y,d2,ob2), we have to visit this again [here x,y are x-coordinates and y-coordinates; d1, d2 are distances from source in the respective
// states; ob1,ob2 are the no of obstacles we can remove ]
// Further explanation can be found in the code section. (Mentioned time and space complexity at the last)


// ---------------------------------------------------------------------------------------------------


// points class in the code represent the state of a cell in the given grid.
class points {
public:

	// x,y: x-coordinates and y- coordinates
	// dist: distance covered from origin
	// obsLeft: no of obstacles we can remove further
	int x, y, dist, obsLeft;

	points(int x, int y, int dist, int obsLeft) {
		this->x = x;
		this->y = y;
		this->dist = dist;
		this->obsLeft = obsLeft;
	}
};

class Solution {
public:
	int shortestPath(vector<vector<int>>& grid, int k) {
		// grid: given binary matrix

		int n = grid.size(), m = grid[0].size();

		// Making a matrix dp to keep track of the states.
		// dp[i][j][k] stores the minimum distance from the source to the cell (i,j) with k no of obstacles can be removed further.
		int dp[n][m][k + 1];

		// initializing the matrix to -1 meaning that no states have been visited yet.
		memset(dp, -1, sizeof(dp));

		// Thisis just an implementation hack to effectively explore the four neighbours of a particular cell
		int dx[4] = { -1, 0, 1, 0};
		int dy[4] = {0, -1, 0, 1};

		// This is the main queue of the BFS
		queue< points > q;

		// Pushing the first cell to the queue and marking that it's visited
		q.push(points(0, 0, 0, k - grid[0][0]));
		dp[0][0][k - grid[0][0]] = 0;


		while (!q.empty()) {

			// take the first element (state) in the queue
			int x = q.front().x;
			int y = q.front().y;
			int dist = q.front().dist;
			int obsLeft = q.front().obsLeft;
			// remove it from the queue
			q.pop();

			// explore all its four neighbour ie. up, left, down and right
			for (int i = 0; i < 4; i++) {

				int newX = x + dx[i]; // x-coordinate of the neighbour
				int newY = y + dy[i]; // y-coordinate of the neighbour
				int newDist = dist + 1; // new distance of the neighbour from the source

				// check if the new coordinate is inside the grid (first four expressions)
				// check if new cell has obstacle then we can remove it or not (we can if obsLeft>=1)
				// finally checking if this state is visited previously
				if ( newX >= 0 &&
				        newX < n &&
				        newY >= 0 &&
				        newY < m &&
				        (obsLeft - grid[newX][newY]) >= 0 &&
				        dp[newX][newY][ (obsLeft - grid[newX][newY]) ] == -1  )
				{
					// if it passes all checks then put this state into the queue and mark as visited as well
					q.push( points(newX, newY, newDist, (obsLeft - grid[newX][newY]) ) );
					dp[newX][newY][ (obsLeft - grid[newX][newY]) ] = newDist;
				}
			}
		}

		// Now think what dp[n-1][m-1][i] (i from 0 to k) will mean (look at the meaning I mentioned previously)
		// Yes, these will contain minimum distance from the source with i no of obstacles which we can remove further.
		// So, the min of those number will contain our ans. If all are not visited then the destination cant be visited.
		int ans = INT_MAX;
		for (int i = 0; i <= k; i++) {
			if ( dp[n - 1][m - 1][i] != -1 ) {
				ans = min(ans, dp[n - 1][m - 1][i] );
			}
		}

		return ans == INT_MAX ? -1 : ans;
	}
};


// Time complexity: At worst case, all the elements in the grid dp will be filled. Since they all are visited once only so the TC will be O(m*n*k)
// Space complexity: O(m*n*k)
