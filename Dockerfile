# Set the base image
FROM php:8.2-apache

# Install necessary extensions
RUN docker-php-ext-install pdo

# Copy website files into the container
COPY . /var/www/html/

# Expose ports
EXPOSE 80 443

# Start Apache
CMD ["apache2ctl", "-D", "FOREGROUND"]
