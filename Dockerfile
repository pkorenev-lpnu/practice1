# Use the official Ubuntu image as the base image
FROM ubuntu:latest

# Set the working directory in the container
WORKDIR /app

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    libboost-all-dev \
    cmake

# Copy the source code into the container
COPY main.cpp .

# Compile the C++ code
RUN g++ -o practice1 main.cpp -lboost_system -lboost_thread -lboost_chrono

# Command to run the API when the container starts
CMD ["./practice1"]
