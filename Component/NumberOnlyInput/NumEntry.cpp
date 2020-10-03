#include "NumEntry.hpp"

void NumEntry::on_insert_text(const Glib::ustring &text, int *position) {
    if (contains_only_numbers(text)) {
        Gtk::Entry::on_insert_text(text, position);
    }
}

bool NumEntry::contains_only_numbers(const Glib::ustring &text) {
    for (unsigned int i = 0; i < text.length(); i++) {
        if (Glib::Unicode::isdigit(text[i]) == false)
            return false;
    }
    return true;
}