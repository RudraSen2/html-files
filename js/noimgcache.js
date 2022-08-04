$(document).ready(function () {
    jQuery('img').each(function () {
        jQuery(this).attr('src', jQuery(this).attr('src') + '?' + (new Date()).getTime());
    });
});