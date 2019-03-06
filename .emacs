(set-face-background 'default "#202020")
(set-face-foreground 'default "white")
(global-linum-mode 1)
(setq show-paren-delay 0)
(show-paren-mode 1)
(custom-set-variables '(inhibit-startup-screen t) '(initial-scratch-message
   ";; This buffer is for notes you don't want to save, and for Lisp evaluation.")
 '(menu-bar-mode nil)
 '(tool-bar-mode nil))
(set-frame-parameter (selected-frame) 'alpha '(85 85))
(add-to-list 'default-frame-alist '(alpha 85 85))
(global-set-key (kbd "M-<up>") 'backward-paragraph) ; M-{
(global-set-key (kbd "M-<down>") 'forward-paragraph) ; M-}
