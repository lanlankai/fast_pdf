function [pd,bin]=fastpdf(x,bin,flag)
% pd=fastpdf(x,bin)
% This code is to estimate the probability density function with a uniform
% bins
% Input
% x is the data to be analyzed
% bin is the specified bins
% 
% Written by Yongxiang HUANG 07/04/2012
% See also: histc, myhist
if nargin==1
    bin=20;
    flag='Y';
end

if nargin==2
    flag='Y'; %exclude zero point
end

Mx=min(size(x));
if Mx>1
    x=reshape(x,numel(x),1);
end


if length(bin)==1
    minx=min(x);
    maxx=max(x);

    bin=linspace(minx,maxx,bin);
    
end

if strcmpi(class(x),'single')
    x=double(x);
    bin=double(bin);
end

pd=fastpdfc(x,bin);

if strcmpi(flag,'Y') %exclude zero point
    xi=pd>0;
    pd=pd(xi);
    bin=bin(xi);
    pd=pd/sum(pd)/(bin(2)-bin(1));
end

if strcmpi(flag,'nor')||strcmp(flag,'nr') %exclude zero point
%     xi=pd==0;
%     pd(xi)=NaN;
    pd=pd/numel(x)/(bin(2)-bin(1));
end
pd=pd(:);
bin=bin(:);

