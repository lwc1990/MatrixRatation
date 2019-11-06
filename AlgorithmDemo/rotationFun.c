//
//  rotationFun.c
//  AlgorithmDemo
//
//  Created by cheyipai on 2019/10/29.
//  Copyright © 2019 cheyipai. All rights reserved.
//

#include "rotationFun.h"
#define N 100
void rotationMatrixTest(){
    printf("请输入矩阵的阶数：");
    int n = 1;
    int originMatrix[N][N];
    int clockwiseRotationMatrix[N][N];
    int anticlockwiseRotationMatrix[N][N];
    scanf("%d",&n);
    //皆以originMatrix的行列为参考
    printf("请输入各元素:\n");
    for(int i = 0; i < n; i ++){//行
        for(int j = 0; j < n;j ++){//列
            int inputNum;
            printf("[%d,%d]=",i,j);
            scanf("%d",&inputNum);
            originMatrix[i][j] = inputNum;
//            clockwiseRotationMatrix[n-j-1][i] = originMatrix[i][j];
//            anticlockwiseRotationMatrix[j][n-i-1] = originMatrix[i][j];
        }
        printf("\n");
    }
    for (int i = 0;i < n; i++) {//列
        for (int j = n - 1;j >= 0; j--) {//行
            clockwiseRotationMatrix[i][n-j-1] = originMatrix[j][i];
        }
    }
    for(int i = n-1;i >= 0;i--){//列
        for(int j = 0;j < n;j++){//行
            anticlockwiseRotationMatrix[n-i-1][j] = originMatrix[j][i];
        }
    }
    printf("输入的原矩阵为：\n");
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            printf("%d    ",originMatrix[i][j]);
        }
        printf("\n");
    }
    printf("原矩阵顺时针旋转90度后的矩阵为：\n");
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            printf("%d    ",clockwiseRotationMatrix[i][j]);
        }
        printf("\n");
    }
    printf("原矩阵逆时针旋转90度后的矩阵为：\n");
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            printf("%d    ",anticlockwiseRotationMatrix[i][j]);
        }
        printf("\n");
    }
}
