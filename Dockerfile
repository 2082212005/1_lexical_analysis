FROM codenvy/cpp_gcc
WORKDIR /app/
COPY ./* ./
RUN chmod +x main.app
RUN g++ main.cpp -o program