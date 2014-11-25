function [norm_xaxis_filt norm_yaxis_filt] = step1(xaxis,yaxis) %#codegen
assert(isa(xaxis,'uint8'));
assert(isa(yaxis,'uint8'));

diff_y = uint8(yaxis - [0 yaxis(1:end-1)]);
yaxis = yaxis(~(diff_y==max(diff_y)));
xaxis = xaxis(~(diff_y==max(diff_y)));

% Char size normalization
array_size = 29;
w = double(max(xaxis));
h = double(max(yaxis));
x_normal = array_size/w;
y_normal = array_size/h;
norm_xaxis = xaxis * x_normal;
norm_yaxis = yaxis * y_normal;

% Removing duplicate coordinates
norm_xy = [norm_xaxis; norm_yaxis];
norm_xy_filt = uint8(unique(norm_xy','rows','first')');
norm_xaxis_filt = norm_xy_filt(1,:);
norm_yaxis_filt = norm_xy_filt(2,:);
