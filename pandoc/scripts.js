<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>\
\
\
\
<script type="text/javascript">\
  \
$(document).ready(function(){\
$(".example").prepend("<h3>Example</h3>");\
\
$(".questionitem").wrap("<ul class=ulquestion></ul>");  \
\
$(".questionitem .question").wrap("<li></li>");  \
$(".questionitem .answered").wrap("<li></li>");  \
\
\
});\
</script>\
