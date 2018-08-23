find . -name "*.sh" | rev | sed 's/\/.*//' | cut -c 4- | rev
