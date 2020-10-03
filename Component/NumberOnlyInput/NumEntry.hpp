#ifndef NUMENTRY_H
#define NUMENTRY_H

#include <gtkmm/entry.h>

class NumEntry : public Gtk::Entry {
  private:
    bool contains_only_numbers(const Glib::ustring &text);

  public:
    void on_insert_text(const Glib::ustring &text, int *position);
};

#endif /* NUMENTRY_H */