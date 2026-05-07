const img = document.getElementById('catImage');
        const btn = document.getElementById('refreshCat');

        btn.addEventListener('click', () => {
            img.src = `/api/cat?${Math.random()}`;
        });