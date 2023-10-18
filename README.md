# Image-color-tampering-judgments-tool
Image-color-tampering-judgment-tool
以上代码是实现一个基于Linux下caffe框架——卷积神经网络图像识别技术的对于图像是否进行颜色篡改的真假图像判断软件的核心代码
具备完整的图像检测模块和用户交互逻辑。 

有了这些代码，任何具有caffe环境的linux用户都可以利用本软件实现对于单张或批量的颜色篡改图像判断。

其中包括：
1、利用共9776张颜色篡改和无篡改图象2000次迭代训练出的caffe-model图像预测模型，是实现预测功能的核心。

2、deploy.prototxt文件：用于图像检测过程的神经网络配置文件，不同学习模型下的不同网络该文件均不同，上传的deploy.prototxt文件是专门用于本图像识别软件的配置文件。

3、mydata_mean.binaryproto数据均值文件：训练数据图片的均值，在测试时使用以加快检测速度。

4、solver_iter_2000.solverstate继续训练文件，由于硬件配置原因，本软件的预测模型经过了2000次训练迭代（一次过程需要10小时，原谅我在linux虚拟机下进行的caffe框架安装，windows太难用了，因此也只能使用cpu训练和预测），如果条件允许，可以在先前训练模型的基础上继续训练。操作可参考：https://blog.csdn.net/wang4959520/article/details/51831637事实是继续训练一定可以增强模型的识别正确率和对其他来源图片的识别能力，因为在训练过程中其loss损失函数的值仍然呈下降趋势，由此判断模型仍有一定的欠拟合。

5、classification.cpp使用模型进行检测的代码：实现caffe下的对图片真假检测功能，规定了模型相关文件调用和输出形式。

6、Interaction_logic.cpp用户交互逻辑的实现代码：由c++语言编写，提供一定程度上优化的用户体验操作，避免用户每次进行判断还要进行原始的sh文件编写和路径修改。

7、labels.txt对应于模型的标签文件：用于表示检测结果。

8、训练的配置文件train_val.prototxt

9、训练的参数文件solver.prototxt：8、9两个文件用于用户对模型进行进一步训练以提高软件检测能力，方便自己进一步使用。

10、start.out软件启动程序

同时为了方便效果检测，上传了4张测试样图（存放在pictures_for_test文件夹中），方便使用者直接测试软件的检测功能

由于本软件涉及到caffe深度学习框架且还没有将软件与caffe集成，所以如果有测试的需求，请安装caffe深度学习框架CPU版
（教程可参考https://blog.csdn.net/c20081052/article/details/79775127）

并下载以上GitHub资源中的software_need文件夹，存放在caffe目录下；

下载start.out文件存放在caffe目录下；

下载classification.cpp文件替换caffe/examples目录下的classification.cpp文件；

在caffe终端执行sudo make all命令。然后就可以使用start.out可执行程序进行软件的使用。

对此带来的不便如果有进一步开发的机会开发者会尝试将安装caffe、环境搭建、和软件功能部分集成在整个软件的安装中以实现软件的一键安装和使用。
