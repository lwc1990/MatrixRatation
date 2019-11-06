//
//  rotationMatrixFunc.c
//  AlgorithmDemo
//
//  Created by cheyipai on 2019/10/30.
//  Copyright © 2019 cheyipai. All rights reserved.
//

#include "rotationMatrixFunc.h"
#include <stdlib.h>
/* 自定义打印函数
 * @param n 为二维方阵的阶数
 * @param arr 为二维方阵
 */
void definePrintFunc(int n,int **matrix){
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
}
/* 根据参数创建二维矩
 * @param n 为二维方阵的阶数
 * @param matrix为二维方阵
 */
int** openUpSpaceFunc(int n){
    int **matrix;
    matrix = (int**)malloc(sizeof(int*)*n);
    for (int i = 0;i < n;i++) {
        matrix[i] = (int*)malloc(sizeof(int)*n);
    }
    return matrix;
}
void rotationMatrixModuleFunc(){
    printf("请输入矩阵的阶数：");
    int n = 1;
    scanf("%d",&n);
    //创建矩阵并动态开辟空间
    int **originMatrix = openUpSpaceFunc(n);
    int **clockwiseRotationMatrix = openUpSpaceFunc(n);
    int **anticlockwiseRotationMatrix = openUpSpaceFunc(n);
    //皆以originMatrix的行列为参考
    printf("请输入各元素:\n");
    for(int i = 0; i < n; i ++){//行
        for(int j = 0; j < n;j ++){//列
            int inputNum;
            printf("[%d,%d] = ",i,j);
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
    definePrintFunc(n, originMatrix);
    printf("原矩阵顺时针旋转90度后的矩阵为：\n");
    definePrintFunc(n, clockwiseRotationMatrix);
    printf("原矩阵逆时针旋转90度后的矩阵为：\n");
    definePrintFunc(n, anticlockwiseRotationMatrix);
    free(originMatrix);
    free(clockwiseRotationMatrix);
    free(anticlockwiseRotationMatrix);
}
