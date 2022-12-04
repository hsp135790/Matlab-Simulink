clear;

%half-car parameter

mc = 700;       %sprung mass[Kg]
mf = 40;        %front upsprung mass [Kg]
mr = 35.5;      %rear unsprung mass[Kg]
lf = 2.3;       %front axle to cog[m]
lr = 2.3;       % cog to rear axle[m]
kfs = 19960;    %front suspension spring rates [N/m]
krs = 17500;    %rear suspension spring rates [N/m]
kft = 175500;   %front tire spring rates[N/m]
krt = 175500;   %rear tire spring rates[N/m]
cfs = 1290;     %front suspension damping coefficient [Ns/m]
crs = 1620;     %rear suspension damping coefficient [Ns/m]
crt = 1000;     %rear suspension damping coefficient [Ns/m]
cft = 1000;     % front tire damping constant [Ns/m]
iyy = 2460;     %inertia of body mass [Kg-m^2]