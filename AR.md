
离线：
得到每个 image 的pose

初始化：
通过提取 Brisk特征点 并且三角化得到 Brisk点云, 将所有Brisk点云放到一个Database 中

Recover:
提取图像中的Brisk点, 和Database中的做匹配， 转化成PNP问题， 求得pose


Tracking:
提取图像中的 Fast点, 提取riff描述子， 将 **相关的FAST点云(带有riff描述子)** 投影下来，找投影点最匹配的的 Fast点，作为匹配， 用这个匹配去优化pose。

相关的Fast点云的获得：
将image分成网格， 每一个小网格中选一个 Fast角点分数最高的点， 找最接近的track，利用这个track的深度信息， 利用当前pose将其反投影， 得到与点云中最接近的Brisk点， 然后



问为什么会