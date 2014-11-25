function char_bin = step2(norm_xaxis_filt,norm_yaxis_filt)  %#codegen
assert(isa(norm_xaxis_filt,'uint8'));
assert(isa(norm_yaxis_filt,'uint8'));

array_size = 29;
% Binarization
char_bin = zeros(array_size+1,array_size+1,'uint8');
len = length(norm_xaxis_filt);
for i=1:len
    char_bin(norm_yaxis_filt(i)+1,norm_xaxis_filt(i)+1) = 1;
end
char_bin = flipud(char_bin);
