{\rtf1\ansi\ansicpg1252\paperw11900\paperh16840\margl1440\margr1440\margt1440\margb1440\vieww18540\viewh17280\viewscale100\lin0\rin0
{\papercolor16777215}
{\fonttbl\f0\fnil\fcharset0 Helvetica;}
{\colortbl\red0\green0\blue0;\red255\green255\blue255;}
\pard
{\*\pageHeader Helvetica::12px::right::black::0.5::NO::Header Author: Zoe Appleseed [date] - Page [pagenumber] of [totalpages]}
{\*\pageFooter Helvetica::12px::right::black::0.5::NO::Footer Author: Zoe Appleseed [title] - Page [pagenumber] of [totalpages]}
{\*\background {\shp{\*\shpinst\shpleft0\shptop0\shpright0\shpbottom0\shpfhdr0\shpbxmargin\shpbymargin\shpwr0\shpwrk0\shpfblwtxt1\shpz0\shplid1025{\sp{\sn shapeType}{\sv 1}}{\sp{\sn fFlipH}{\sv 0}}{\sp{\sn fFlipV}{\sv 0}}{\sp{\sn fillColor}{\sv 16777215}}{\sp{\sn fFilled}{\sv 1}}{\sp{\sn lineWidth}{\sv 0}}{\sp{\sn fLine}{\sv 0}}{\sp{\sn bWMode}{\sv 9}}{\sp{\sn fBackground}{\sv 1}}}}}

\f0\fs24 \cf0 #include iostream>using namespace std;void move(char src,char dest)    cout  src  "-->"  dest endl; //\u25226?src\u38024?\u30340?\u26368?\u19978?\u38754?\u19968?\u20010?\u30424?\u23376?\u31227?\u21160?\u21040?dest\u38024?\u19978?void hanoi(int n,char src,char medium,char dest)//\u23558?n\u20010?\u30424?\u23376?\u20174?src\u38024?\u31227?\u21160?\u21040?dest\u38024?\u65292?\u20197?medium\u38024?\u20026?\u20013?\u36716?    if(n==1)        move(src,dest);    else            hanoi(n-1,src,dest,medium);        move(src,dest);        hanoi(n-1,medium,src,dest);    int main()    int m;    cout  "Enter the number of disks:";    cin >> m;    cout  "The steps to moving " m  " disks:"  endl;    hanoi(m,'A','B','C');    return 0;\
}