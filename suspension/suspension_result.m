close all
tfinal = 558;
x = out.tout(1:tfinal);

%%%%%%%%%%%%%%%%%%%%%%%%%Road condition1

%Pitch
%%subplot(3,2,1),plot(x,out.P_pitch(1:tfinal),'b','DisplayName','Passive'),hold on,plot(x,out.G_pitch(1:tfinal),'y','DisplayName','Ground'),hold on, plot(x,out.S_pitch(1:tfinal),'r','DisplayName','Sky'),hold on, plot(x,out.H_pitch(1:tfinal),'m','DisplayName','Hybrid'),legend('show'),title('Pitch(Road Condition1)'),ylabel('Angle(Degree)');

%Angular Velocity
%%plot(x,out.P_av(1:tfinal),'b','DisplayName','Passive'),hold on,plot(x,out.G_av(1:tfinal),'y','DisplayName','Ground'),hold on, plot(x,out.S_av(1:tfinal),'r','DisplayName','Sky'),hold on, plot(x,out.H_av(1:tfinal),'m','DisplayName','Hybrid'),legend('show'),title('Angular Velocity(Road Condition1)'),ylabel('Speed(rad/sec)');

%Body displacement
plot(x,out.P_bd(1:tfinal),'b','DisplayName','Passive'),hold on,plot(x,out.G_bd(1:tfinal),'y','DisplayName','Ground'),hold on, plot(x,out.S_bd(1:tfinal),'r','DisplayName','Sky'),hold on, plot(x,out.H_bd(1:tfinal),'m','DisplayName','Hybrid'),legend('show'),title('Body Displaement(Road Condition1)'),ylabel('Displacement');

%Front displacement
%%subplot(3,2,4),plot(x,out.P_fd(1:tfinal),'b','DisplayName','Passive'),hold on,plot(x,out.G_fd(1:tfinal),'y','DisplayName','Ground'),hold on, plot(x,out.S_fd(1:tfinal),'r','DisplayName','Sky'),hold on, plot(x,out.H_fd(1:tfinal),'m','DisplayName','Hybrid'),legend('show'),title('Front Wheel Displaement(Road Condition1)'),ylabel('Displacement');

%Rear displacement
%%subplot(3,2,5),plot(x,out.P_rd(1:tfinal),'b','DisplayName','Passive'),hold on,plot(x,out.G_rd(1:tfinal),'y','DisplayName','Ground'),hold on, plot(x,out.S_rd(1:tfinal),'r','DisplayName','Sky'),hold on, plot(x,out.H_rd(1:tfinal),'m','DisplayName','Hybrid'),legend('show'),title('Rear Wheel Displaement(Road Condition1)'),ylabel('Displacement');


grid on;
hold off;
