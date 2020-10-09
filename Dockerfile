FROM codenvy/cpp_gcc
WORKDIR /app/
COPY ./* /app/
RUN chattr -i main.cpp
RUN chmod 777 main.cpp
RUN g++ main.cpp -o program -v
RUN chmod +x program