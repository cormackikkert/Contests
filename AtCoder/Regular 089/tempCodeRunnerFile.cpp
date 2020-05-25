int best = 0;

	// for (int x = 0; x < K; ++x) {
	// 	for (int y = 0; y < K; ++y) {
	// 		for (bool col : {false, true}) {
				
	// 			// print("REE -- ", x, y, col);
	// 			int cur = 0;
	// 			for (int dx : {-1, 0, 1}) {
	// 				for (int dy : {-1, 0, 1}) {
	// 					bool c = col ^ ((dx + dy + 2) % 2 == 0);
	// 					// print(x + dx * K, y + dy * K, c, "->", getCount(x + dx * K, y + dy * K, c));
	// 					cur += getCount(x + dx * K, y + dy * K, c);
	// 				}
	// 			}

	// 			// print(cur);
	// 			best = max(best, cur);
	// 		}
	// 	}
	// }