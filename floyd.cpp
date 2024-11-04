import java.util.Arrays;

public class FloydWarshall {
		final static int INF = 99999;

		void floydWarshall(int graph[][]) {
			int V = graph.length;
			int dist[][] = new int[V][V];

			// 初始化距离矩阵
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {
					dist[i][j] = graph[i][j];
				}
			}

			// 三重循环更新距离
			for (int k = 0; k < V; k++) {
				for (int i = 0; i < V; i++) {
					for (int j = 0; j < V; j++) {
						if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
							dist[i][j] = dist[i][k] + dist[k][j];
						}
					}
				}
			}

			// 打印最短路径矩阵
			printSolution(dist);
		}

		void printSolution(int dist[][]) {
			System.out.println("最短路径矩阵: ");
			for (int i = 0; i < dist.length; ++i) {
				for (int j = 0; j < dist.length; ++j) {
					if (dist[i][j] == INF)
						System.out.print("INF ");
					else
						System.out.print(dist[i][j] + "   ");
				}
				System.out.println();
			}
		}

		public static void main(String[] args) {
			int graph[][] = {
				{0, 3, INF, 7},
				{8, 0, 2, INF},
				{5, INF, 0, 1},
				{2, INF, INF, 0}
			};

			FloydWarshall a = new FloydWarshall();
			a.floydWarshall(graph);
		}
}
