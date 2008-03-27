/* helpmenu.c  -  The GNU Privacy Assistant
   Copyright (C) 1995 Spencer Kimball and Peter Mattis
   Copyright (C) 2000, 2001 G-N-U GmbH.
   Copyright (C) 2008 g10 Code GmbH.

   This file is part of GPA.

   GPA is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   GPA is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.  */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <gtk/gtk.h>

#include "gpa.h"
#include "icons.h"
#include "gpl-text.h"
#include "helpmenu.h"


/* Display the about dialog.  */
static void
help_about (GtkWindow *window)
{
  static const gchar *authors[] =
    {
      "Andy Ruddock",
      "Beate Esser",
      "Benedikt Wildenhain",
      "Bernhard Herzog",
      "Can Berk Güder",
      "Daniel Nylander",
      "Emilian Nowak",
      "Jan-Oliver Wagner",
      "Josué Burgos",
      "Ling Li",
      "Marcus Brinkmann",
      "Markus Gerwinski",
      "Maxim Britov",
      "Michael Anckaert",
      "Michael Fischer v. Mollard",
      "Michael Mauch",
      "Mick Ohrberg",
      "Miguel Coca",
      "Peter Gerwinski",
      "Peter Hanecak",
      "Peter Neuhaus",
      "Renato Martini",
      "Shell Hung",
      "Werner Koch",
      "Yasunari Imado",
      "Zdenek Hatas",
      NULL
    };
  static const gchar copyright[] =
    "Copyright \xc2\xa9 2000-2002 G-N-U GmbH\n"
    "Copyright \xc2\xa9 2002-2003 Miguel Coca\n"
    "Copyright \xc2\xa9 2005-2008 g10 Code GmbH";
#ifdef HAVE_W32_SYSTEM
  static const gchar website[] = "http://www.gpg4win.org/";
#else
  static const gchar website[] = "http://www.gnupg.org/";
#endif

  GdkPixbuf *logo;

  logo = gpa_create_icon_pixbuf ("gpa_logo");
  gtk_show_about_dialog (window,
			 "program-name", "GPA",
			 "version", VERSION,
			 "title", _("About GPA"),
			 /* Only clickable if
			    gtk_about_dialog_set_url_hook() is
			    used.  */
			 "website", website,
			 "copyright", copyright,
			 "comments", _("GPA is the GNU Privacy Assistant."),
			 "authors", authors,
			 "license", get_gpl_text (),
			 "logo", logo,
			 NULL);
  if (logo)
    g_object_unref (logo);
}

void
help_help (GtkWindow *window)
{
  g_print (_("Show Help Text\n"));
}


void
gpa_help_menu_add_to_factory (GtkItemFactory *factory, GtkWidget * window)
{
  GtkItemFactoryEntry menu[] = {
    { _("/_Help"), NULL, NULL, 0, "<Branch>" },
#if 0
    /* FIXME: Help is not available yet.  */
    { _("/Help/_Contents"), NULL, (GtkItemFactoryCallback) help_help, 0,
      "<StockItem>", GTK_STOCK_HELP },
#endif
    { _("/Help/_About"), NULL, (GtkItemFactoryCallback) help_about, 0,
      "<StockItem>", GTK_STOCK_ABOUT }
  };
  gtk_item_factory_create_items (factory, sizeof (menu) / sizeof (menu[0]),
				 menu, window);
}
