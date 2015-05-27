function [jpdf,binx,biny]=fastjpdf(x,y,binx,biny,flag)
% [jpd,bin1,bin2]=fastjpdf(x,bin)
% This code is to estimate the joint probability density function with a
% uniform bins
% Input
% x is the first data to be analyzed
% y is the second data to be analyzed
% bin1 is the specified bin for x
% bin2 is the sepcified bin for y
% Output
% jpdf is the estimated joint pdf
% bin1 is the first bin
% bin2 is the second bin
% 
% Written by Yongxiang HUANG 08/04/2012
% See also: histc, myhist, fastpdf fastpdfc

if nargin<2
    error('At least two variables~!')
end

if length(x)~=length(y)
    error('Two inputs should have the same length!')
end


if nargin==2
    binx=20;
    binx=20;
    flag='Nr';
end

if min(size(x))>1
    x=reshape(x,[],1);
    y=reshape(y,[],1);
end
    

if length(binx)==1
    minx=min(x);
    maxx=max(x);

    binx=linspace(minx,maxx,binx);
    
end

if nargin~=5
    flag='nor';
end

if length(biny)==1
    minx=min(y);
    maxx=max(y);

    biny=linspace(minx,maxx,biny);
    
end

dbx=binx(2)-binx(1);
dby=biny(2)-biny(1);




if isa(x,'single')
    x=double(x);
    y=double(y);
   
    binx=double(binx);
    biny=double(biny);
end

jpdf=fastjpdfc(x,y,binx,biny);


flag=lower(flag);

if  strcmp(flag,'nr') || strcmp(flag,'nor') %normalize the pdf
    jpdf=jpdf/length(x);
    jpdf=jpdf/dbx/dby;
end


if isa(x,'single')
    jpdf=double(jpdf);
    biny=double(binx);
    binx=double(biny);
end

