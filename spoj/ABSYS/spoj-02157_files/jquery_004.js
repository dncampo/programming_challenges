	$(document).ready(function() {
		 $("a[id*=cx_].cxhelp").each(function() {
			$(this).tooltip({
				track: true, 
			    delay: 0, 
			    showURL: false,  
			    fade: 100,
			    bodyHandler: function() { 
			        return $("#h_" + $(this).attr("id").substr(3)).html();
			    }
		 	});
			$(this).text("?");
		 });

		$("[id*=cx_].cxhelp2").each(function() {
                        $(this).tooltip({
                                track: true,
                            delay: 0,
                            showURL: false,
                            fade: 100,
			    id: "tooltip2",
                            bodyHandler: function() {
                                return $("#h_" + $(this).attr("id").substr(3)).html();
                            }
                        });
                 });
	});
