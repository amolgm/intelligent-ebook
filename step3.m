function char_vec = step3(char_bin)     %#codegen
assert(isa(char_bin,'uint8'));

% Noise removal

% For edge elements
pic_dim = 30;   %(array_size+1)

% Bottom edge (last row)
for i=1:pic_dim
    if char_bin(pic_dim,i)==1
        if i == 1 && char_bin(pic_dim-1,1)==0 && char_bin(pic_dim,2)==0
            char_bin(pic_dim,1) = 0;
        elseif i == pic_dim && char_bin(pic_dim-1,pic_dim)==0 && ...
                char_bin(pic_dim,pic_dim-1) == 0
            char_bin(pic_dim,pic_dim) = 0;
        elseif i~=1 && i~=pic_dim
            if char_bin(pic_dim,i-1)==0 && char_bin(pic_dim,i+1)==0 && ...
                char_bin(pic_dim-1,i)==0
            char_bin(pic_dim,i) = 0;
            end
        end    
    end
end

% Top edge (first row)
for i=1:pic_dim
    if char_bin(1,i)==1
        if i == 1 && char_bin(2,1)==0 && char_bin(1,2)==0
            char_bin(1,1) = 0;
        elseif i == pic_dim && char_bin(1,pic_dim-1)==0 && ...
                char_bin(2,pic_dim) == 0
            char_bin(1,pic_dim) = 0;
        elseif i~=1 && i~=pic_dim
            if char_bin(1,i-1)==0 && char_bin(1,i+1)==0 && ...
                char_bin(2,i)==0
            char_bin(1,i) = 0;
            end
        end
    end
end

% Left edge (first column)
for i=2:pic_dim-1
    if char_bin(i,1)==1
        if char_bin(i-1,1)==0 && char_bin(i+1,1)==0 && ...
                char_bin(i,2)==0
            char_bin(i,1) = 0;
        end            
    end
end

% Right edge (last column)
for i=2:pic_dim-1
    if char_bin(i,pic_dim)==1
        if char_bin(i-1,pic_dim)==0 && char_bin(i+1,pic_dim)==0 && ...
                char_bin(i,pic_dim-1)==0
            char_bin(i,pic_dim) = 0;
        end 
    end
end

% for between the image
for i=2:size(char_bin,1)-1
    for j=2:size(char_bin,1)-1
        if char_bin(i,j) == 1
              if char_bin(i,j+1)==0 && char_bin(i,j-1)==0 && ...
                      char_bin(i+1,j)==0 && char_bin(i-1,j)==0
                  char_bin(i,j)=0;
              end
        end
    end
end

char_hz = uint8([sum(sum(char_bin(1:6,:))); sum(sum((char_bin(7:12,:)))); ...
    sum(sum(char_bin(13:18,:))); sum(sum(char_bin(19:24,:))); ...
    sum(sum(char_bin(25:30,:)))]);
char_vt = uint8([sum(sum(char_bin(:,1:6))); sum(sum(char_bin(:,7:12))); ...
    sum(sum(char_bin(:,13:18))); sum(sum(char_bin(:,19:24))); ...
    sum(sum(char_bin(:,25:30)))]);

char_vec = uint8([char_hz; char_vt]);