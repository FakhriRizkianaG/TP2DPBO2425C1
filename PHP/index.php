<?php
require_once "Handphone.php";

$hpList = [
    new Handphone("P001", "Galaxy S21", 15000000, "images/Phone1.png",
        "Snapdragon 888", 8, 256, 4000, "Samsung", "S", "Android"),
    new Handphone("P002", "iPhone 14", 18000000, "images/Phone2.png",
        "A15 Bionic", 6, 128, 3800, "Apple", "14", "iOS"),
    new Handphone("P003", "Pixel 7", 12000000, "images/Phone3.png",
        "Tensor G2", 8, 128, 4350, "Google", "7", "Android"),
    new Handphone("P004", "Xiaomi 13", 9000000, "images/Phone4.png",
        "Snapdragon 8 Gen 2", 12, 256, 4820, "Xiaomi", "13", "Android"),
    new Handphone("P005", "OnePlus 11", 11000000, "images/Phone5.png",
        "Snapdragon 8 Gen 2", 16, 256, 5000, "OnePlus", "11", "Android"),
];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Daftar Handphone</title>
    <!-- ✅ External CSS -->
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <h2>Daftar Handphone</h2>

    <table>
        <tr>
            <th>ID</th>
            <th>Nama</th>
            <th>Series</th>
            <th>Manufaktur</th>
            <th>OS</th>
            <th>Processor</th>
            <th>RAM</th>
            <th>Storage</th>
            <th>Battery</th>
            <th>Harga</th>
            <th>Image</th>
        </tr>
        <?php foreach ($hpList as $hp): ?>
        <tr>
            <td><?= $hp->getIdProduk(); ?></td>
            <td><?= $hp->getNama(); ?></td>
            <td><?= $hp->getSeries(); ?></td>
            <td><?= $hp->getManufaktur(); ?></td>
            <td><?= $hp->getTipeOS(); ?></td>
            <td><?= $hp->getProcessor(); ?></td>
            <td><?= $hp->getRam(); ?> GB</td>
            <td><?= $hp->getStorage(); ?> GB</td>
            <td><?= $hp->getBattery(); ?> mAh</td>
            <td>Rp. <?= number_format($hp->getHarga(), 0, ',', '.'); ?></td>
            <td><img src="<?= $hp->getImage(); ?>" alt="<?= $hp->getNama(); ?>"></td>
        </tr>
        <?php endforeach; ?>
    </table>
</body>
</html>
