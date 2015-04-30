/*
 * Yongxiang Huang, last modification: 05/10/2014
 * yongxianghuang@gmail.com
 *
 */

/* This function is to perform distance condtioned statistics
 */

#include <stdlib.h>
#include <stdio.h>
#include "mex.h"
#include <math.h>
#include <time.h>





/************************************************************************/
/*                                                                      */
/* MAIN FUNCTION                                                        */
/*                                                                      */
/************************************************************************/

void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[]) {
    
    /* declarations */
    
    int i,it,j,k,Nx,tn,NBin;
    
    double *x,*bin,hbin,tmp;
    double *pdf;
    
    
    /*     check input*/
    if (nrhs!=2)     mexErrMsgTxt("You have to input two parameters!");
    if (mxIsEmpty(prhs[0]))mexErrMsgTxt("x is empty!");
    if (mxIsEmpty(prhs[1]))mexErrMsgTxt("bin is empty!");
    
    /* get input data */
    
    x=mxGetPr(prhs[0]);
    bin=mxGetPr(prhs[1]);
    
    
    Nx=mxGetN(prhs[0]);
    tn=mxGetM(prhs[0]);
    Nx=(int) Nx*tn;
    
    NBin=mxGetN(prhs[1]);
    tn=mxGetM(prhs[1]);
    if (tn>NBin) NBin=tn;
    
    
    
    hbin=(bin[1]-bin[0]);
    
    
    plhs[0]=mxCreateDoubleMatrix(NBin,1,mxREAL);
    pdf=mxGetPr(plhs[0]);
    
    /*fast algorithm to calculate the pdf*/
    
    for(i=0;i<Nx;i++){
        
        tmp=(x[i]-bin[0])/hbin+0.5;/*calculate the index*/
        it=(int) floor(tmp); /*take the integer number*/
        
        if (it>=0 && it<NBin ) pdf[it]=pdf[it]+1.0;
        
    }
    
    
    
}






