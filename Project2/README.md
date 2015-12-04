Programmer: Michael Overy
Assignment: Project 2: Pairwise Clustering

Summary:

Take the item in lab6 and alter it to cluster using a groupwise method instead of a centroid. Also mke sure the algorithm is efficient and does not recompute the distance between clusters.


Changes from lab6:

	1.) Added a function clusterDistance that calls the function myDistance which was used in lab6
	2.) Changed formatting and added information about each merge
	3.) Used a vector<vector<double>> called cache to keep track of items so they don't need to be recomputed. I found that for my algorithm every time a cluster is merged, the shortestI'th row and column in the cache had to be recomputed, and the shortestJ'th row and column must be removed completely.

Notes:

	1.) Works with both test cases provided by the professor
	2.) The items in each cluster are all correct, but may be listed in a different order.
	3.) If you are getting incorrect results it is likely due to the caching mechanism being faulty. At line 74, replace 'if(cache[i][j] == -2)' with 'if(true)'. This will cause the distances to be recomputed every time instead of checking if they need to be recomputed. While slower, it should provide correct results.
	
	4.) Where I edit the cache I have a flag determining whether or not I change an item in the I'th column to -2 or not. If I found a -2 already, I stop altering items in that column. This is mainly to prevent mangling the stack, as I was running into segmentation faults on the return statement without this line of defense
