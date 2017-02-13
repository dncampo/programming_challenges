	//jak uzywac pomocy kontekstowej? - docs/help/faq/context_help

	function refresh_cxhelp_tooltips() {
		
			 $("a[id*=cx_].cxhelp").each(function() {
				$(this).tooltip({
					track: true, 
				    delay: 0, 
				    showURL: false,  
				    fade: 100,
				    extraClass: "standardTooltipWidth",
				    bodyHandler: function() { 
				        return $("#h_" + $(this).attr("id").substr(3)).html();
				    }
			 	});
				$(this).text("?");
			 });
			 
			 
			 $("a[id*=cx_][class*=cxhelp_w]").each(function() {
				 var width = $(this).attr("class").substr(8);
				 var newClassName = "tooltipWidth" + width;
				 var newClass = "<style>." + newClassName + " { width: " + width + "px; } </style>";
				 $("body").append(newClass);
				 $(this).tooltip({
						track: true, 
					    delay: 0, 
					    showURL: false,  
					    fade: 100,
					    extraClass: newClassName,
					    bodyHandler: function() { 
					        return $("#h_" + $(this).attr("id").substr(3)).html();
				    }
				});
				$(this).addClass("cxhelp");
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
	}
	
	$(document).ready(function() {
		refresh_cxhelp_tooltips();
	});
