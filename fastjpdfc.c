/*
* Yongxiang Huang, last modification: 25/05/2015
* yongxianghuang@gmail.com
*
*/

/* This function is to calculate the joint pdf 
 Input:
 * x is the first variable
 * y is the second variable
 * binx is the bin of x
 * biny is the bin of y
 Output
 * jpdf is the calculated joint pdf
 */

#include <stdlib.h>
#include <stdio.h>
#include "mex.h"
#include "math.h"




/************************************************************************/
/*                                                                      */
/* MAIN FUNCTION                                                        */
/*                                                                      */
/************************************************************************/

void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[]) {
  
    /* declarations */
    int i,j,Nbx,Nby,ntmp,Nx,Ny,indx,indy;
    
    double *x,*y,*jpdf,*binx,*biny; 

  
    
/*     check input*/
    if (nrhs!=4)     mexErrMsgTxt("You have to give two parameters!");
    if (mxIsEmpty(prhs[0]))mexErrMsgTxt("x is empty!");
    if (mxIsEmpty(prhs[1]))mexErrMsgTxt("y is empty!");
    if (mxIsEmpty(prhs[2]))mexErrMsgTxt("binx is empty!");
    if (mxIsEmpty(prhs[3]))mexErrMsgTxt("biny is empty!");
    /* get input data */
    x=mxGetPr(prhs[0]); /* get x*/
    y=mxGetPr(prhs[1]);/* get y*/
    binx=mxGetPr(prhs[2]);/* get binx*/
    biny=mxGetPr(prhs[3]);/* get biny*/
    
    Nx=mxGetN(prhs[0]); /* get the length of x*/
    ntmp=mxGetM(prhs[0]);
    if (ntmp>Nx)Nx=ntmp;
    
    Ny=mxGetN(prhs[1]);/* get the length of y*/
    ntmp=mxGetM(prhs[1]);
    if (ntmp>Ny)Ny=ntmp;
    
    if(Nx!=Ny)mexErrMsgTxt("The length of x and y must be the same!");
    
    
    Nbx=mxGetN(prhs[2]);/* get the length of binx*/
    ntmp=mxGetM(prhs[2]);
    if (ntmp>Nbx)Nbx=ntmp;
    
    Nby=mxGetN(prhs[3]);/* get the length of biny*/
    ntmp=mxGetM(prhs[3]);
    if (ntmp>Nby)Nby=ntmp;
    
    
    
   
    
    plhs[0]=mxCreateDoubleMatrix(Nby,Nbx,mxREAL); /*prepare the output*/
    jpdf=mxGetPr(plhs[0]);
    
    for (i=0;i<Nbx;i++)for(j=0;j<Nby;j++)jpdf[i*Nby+j]=0.0;
    
    for(i=0;i<Nx;i++)
    {
        indx=(int) floor((x[i]-binx[0])/(binx[1]-binx[0])+0.5);
        indy=(int) floor((y[i]-biny[0])/(biny[1]-biny[0])+0.5);
        if(indx>-1 & indx<Nbx & indy>-1 & indy<Nby)
        {
            jpdf[indx*Nby+indy]=jpdf[indx*Nby+indy]+1.0;
        }
        
    }
    
    
}
 
   
