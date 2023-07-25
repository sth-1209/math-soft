import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from tempfile import NamedTemporaryFile
import subprocess

# 从 dimension.txt 文件中读取椭球轴长度
with open("dimension.txt", "r") as f:
    lines = f.readlines()
a = float(lines[0].strip())
b = float(lines[1].strip())
c = float(lines[2].strip())

# 生成椭球数据点
u = np.linspace(0, 2 * np.pi, 100)
v = np.linspace(0, np.pi, 50)
u, v = np.meshgrid(u, v)
x = a * np.cos(u) * np.sin(v)
y = b * np.sin(u) * np.sin(v)
z = c * np.cos(v)


# 绘制椭球图形
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(x, y, z, cmap='viridis')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
plt.savefig("ellipsoid.pdf", format='pdf')
plt.close()

